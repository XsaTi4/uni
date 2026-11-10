
def scholarship(grades):
    sevens = 0

    for grade in grades:
        if grade < 7:
            return False

        if grade == 7:
            sevens += 1

    return sevens <= 2


input_name = input("Input filename: ")
output_name = input("Output filename: ")

with open(input_name, "r", encoding="utf-8") as input_file, \
     open(output_name, "w", encoding="utf-8") as output_file:

    for line in input_file:
        parts = line.split()

        if len(parts) < 3:
            continue

        name = parts[0]
        surname = parts[1]
        grades = [int(grade) for grade in parts[2:]]

        if scholarship(grades):
            sevens = grades.count(7)

            result = f"{name} {surname} {sevens}"

            print(result)
            output_file.write(result + "\n")
