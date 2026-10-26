#include <iostream> 
#include <array>

using namespace std;
using Matrix = array<array<int , 10>, 10>;

int choose() {
    int option;
    cout << "1 - A \n2 - B" << endl;
    cin >> option;
    switch(option) {
        case 1:
            return option;
        case 2:
            return option;
        default:
            cout << "Error!" << endl;
            return 1;
    }
}

Matrix generator(int& choose, Matrix& matrix){
    
    int number = 1;

    if (choose == 1) {
        
        for (int column = 0; column < 10; column++) {
            int firstRow;

            if (column > 3) {
                firstRow = column - 3;
            }
            else {
                firstRow = 0;
            }
            for (int row = firstRow; row <= column; row++) {
                matrix[row][column] = number;
                number++;
            }
        }
    }
    else if (choose == 2){ 
        for (int row = 0; row < 10; row++){
            for (int column = 0; column < 10; column++){
                if (column < row){
                    matrix[column][row] = row - column;
                }
            }
        }
    }

    return matrix;

}

void printMatrix(const Matrix& matrix){
    for (const auto& row : matrix){
        for (int value : row) {
            cout << value << '\t';

        }
        cout << '\n';
    }

}

int main() {

    Matrix matrix{};
    cout << "Ruslans Popakuls" << '\n'<< "stud numb" << endl;

        int option = choose();
        matrix = generator(option, matrix);

        printMatrix(matrix);
    

}