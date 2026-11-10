from pathlib import Path
import sys


def run(path):
    source = path.read_text(encoding="utf-8")
    code = "".join(symbol for symbol in source if symbol in "><+-.,[]")
    jumps = {}
    stack = []

    for position, symbol in enumerate(code):
        if symbol == "[":
            stack.append(position)
        elif symbol == "]":
            if not stack:
                raise ValueError("Unmatched closing bracket")
            opening = stack.pop()
            jumps[opening] = position
            jumps[position] = opening

    if stack:
        raise ValueError("Unmatched opening bracket")

    memory = [0] * 30000
    pointer = 0
    position = 0

    while position < len(code):
        symbol = code[position]
        if symbol == ">":
            pointer += 1
            if pointer >= len(memory):
                raise ValueError("Memory limit exceeded")
        elif symbol == "<":
            pointer -= 1
            if pointer < 0:
                raise ValueError("Pointer moved before the start of memory")
        elif symbol == "+":
            memory[pointer] = (memory[pointer] + 1) % 256
        elif symbol == "-":
            memory[pointer] = (memory[pointer] - 1) % 256
        elif symbol == ".":
            sys.stdout.buffer.write(bytes([memory[pointer]]))
            sys.stdout.buffer.flush()
        elif symbol == ",":
            value = sys.stdin.buffer.read(1)
            memory[pointer] = value[0] if value else 0
        elif symbol == "[" and memory[pointer] == 0:
            position = jumps[position]
        elif symbol == "]" and memory[pointer] != 0:
            position = jumps[position]
        position += 1


if __name__ == "__main__":
    try:
        run(Path(__file__).with_name("Main.bf"))
    except (OSError, ValueError) as error:
        print(f"Error: {error}", file=sys.stderr)
        sys.exit(1)
    except KeyboardInterrupt:
        print("\nStopped.", file=sys.stderr)
        sys.exit(130)
