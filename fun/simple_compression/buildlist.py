#!/bin/python
import random
import sys

def generate_byte_buckets(total_values:int, value_size_in_bytes: int) -> list[tuple[int, int, int]]:
    output: list[tuple[int, int, int]] = []

    min: int = 0x00
    max: int = 0xFF

    maximum: int = sum(0xFF << (8 * i) for i in range(value_size_in_bytes))
    
    bucket_size: int = total_values // value_size_in_bytes
    remainder: int = total_values % value_size_in_bytes

    while max <= maximum:
        output.append((min, max, bucket_size + 1 if remainder > 0 else bucket_size))

        remainder -= 1
        
        min = max + 1
        max = max << 8 | 0xFF

    return output


def generate_random_int_list(min: int, max: int, count: int) -> list[int]:
    return [random.randint(min, max) for _ in range(count)]
    # output: list[int] = []

    # for _ in range(count):
    #     output.append(random.randint(min, max))
    
    # return output


def main():
    output: list[int] = []
    count: int = 10
    byte_width: int = 4

    if len(sys.argv) > 2:
        sys.stderr.write("Usage: python buildlist.py [how many numbers to generate]\n")
        sys.stderr.write("Example: python buildlist.py 100\n")
        return

    if len(sys.argv) == 2:
        try:
            count = int(sys.argv[1])
        except ValueError:
            sys.stderr.write("Please pass a valid number.\n")
            return
    
    for bucket in generate_byte_buckets(count, byte_width):
        output += generate_random_int_list(*bucket)

    random.shuffle(output)

    for index, v in enumerate(output):
        sys.stdout.write(f"{v}" if index == len(output) - 1 else f"{v}\n")

if __name__ == "__main__":
    main()