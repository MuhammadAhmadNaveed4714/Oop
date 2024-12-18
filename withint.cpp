#include <iostream>
#include <string>
#include <cstdlib>  // for atoi function

using namespace std;

class MatrixSolver {
private:
    int coefficientMatrix[3][3];  // Coefficient matrix (3x3)
    int constantMatrix[3][1];     // Constant matrix (3x1)
     //Helper function to extract coefficient of a term
    int extractCoefficient(const string& term, char var) {
        int coeff = 0;
        size_t var_pos = term.find(var);
        if (var_pos != string::npos) {
            string coeff_str = term.substr(0, var_pos);
            if (term[0] == term[var_pos])
            {
                cout << "\nYou must enter constant with variable.\n";
                exit(1);
            }
            /*if (coeff_str.empty() || coeff_str == "+" || coeff_str == "-") {
                coeff = (coeff_str == "-" || coeff_str.empty()) ? -1 : 1;
            }*/
            else {
                coeff = stoi(coeff_str);
                // Convert string to integer
            }
        }
        return coeff;
    }
    


public:
    // Convert the system of equations into coefficient and constant matrices
    void convertStringsToMatrix(string equations[3]) {
        for (int i = 0; i < 3; i++) {
            string equation = equations[i];
            string term = "";
            bool isConstant = false;
            int index = 0;
            for (size_t j = 0; j < equation.length(); j++) {
                char c = equation[j];
               if (c == '-')
                {
                    cout << "\nYou must not enter negative value.\n";
                    exit(1);
                }
                if (c == '+' ||c=='-'||c == '=' || c == ' ') {
                    if (!term.empty()) {
                        if (isConstant) {
                            constantMatrix[i][0] = stoi(term);  // Set constant value
                        }
                        else {
                       
                            // Check for variables x, y, z and set the corresponding coefficient
                             if (term.find('x') != string::npos) {
                                coefficientMatrix[i][0] = extractCoefficient(term, 'x');
                            }
                            else if (term.find('y') != string::npos) {
                                coefficientMatrix[i][1] = extractCoefficient(term, 'y');
                            }
                            else if (term.find('z') != string::npos) {
                                coefficientMatrix[i][2] = extractCoefficient(term, 'z');
                            }
                            else if ((term.find('x') == string::npos) || (term.find('y') == string::npos) || (term.find('z') == string::npos))
                            {
                                cout << "\nYou have entered wrong variable.\n";
                                exit(1);
                            }
                        }
                    }
                    term = "";  // Reset term for the next one
                    if (c == '=') {
                        isConstant = true;  // After '=' sign, the remaining part is constant
                    }
                }
                else {
                    term += c;  // Add character to the current term
                }
            }

            // If there's any leftover term after the loop, it's the constant term
            if (!term.empty()) {
                constantMatrix[i][0] = stoi(term);
            }
        }
    }

    int calculateDeterminant() {
        int a = coefficientMatrix[0][0], b = coefficientMatrix[0][1], c = coefficientMatrix[0][2];
        int d = coefficientMatrix[1][0], e = coefficientMatrix[1][1], f = coefficientMatrix[1][2];
        int g = coefficientMatrix[2][0], h = coefficientMatrix[2][1], i = coefficientMatrix[2][2];

        // Applying the determinant formula for a 3x3 matrix
        int determinant = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
        return determinant;
    }

    int minor(int i, int j) {
        // Create a 2x2 submatrix by excluding the i-th row and j-th column
        int submatrix[2][2];
        int subrow = 0, subcol = 0;

        // Loop over the matrix and form the 2x2 submatrix
        for (int row = 0; row < 3; row++)
        {
            if (row == i)
            {
                continue;  // Skip the i-th row
            }
            subcol = 0;
            for (int col = 0; col < 3; col++) {
                if (col == j)
                {
                    continue;  // Skip the j-th column
                }
                submatrix[subrow][subcol] = coefficientMatrix[row][col];
                subcol++;
            }
            subrow++;
        }

         //The determinant of the 2x2 matrix is given by:
        int subdet = submatrix[0][0] * submatrix[1][1] - submatrix[0][1] * submatrix[1][0];
        return subdet;
    }
    
    int cofactor(int i, int j) {
        // Calculate the minor first
        double m = minor(i, j);

        // Multiply the minor by (-1)^(i+j)
        int cofactorValue = (i + j) % 2 == 0 ? m : -m;
        return cofactorValue;
    }

    
    

    // Print the coefficient and constant matrices
    void printMatrices()
    {
        cout << "Coefficient Matrix (A):" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << coefficientMatrix[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Constant Matrix (B):" << endl;
        for (int i = 0; i < 3; i++) {
            cout << constantMatrix[i][0] << endl;
        }
    }
};

int main() {
    MatrixSolver solver;
    string equations[3];
    cout << "Enter three equations (e.g., 2x+3y+6z=32):" << endl;
    cout << "\nEnter constant with variable otherwise the program will not work.\n";
    cout << "\nYou cannot enter varibles other than x,y and z.\n";
    cout << "\nThe code will only work for positive values.\n";
    for (int i = 0; i < 3; i++) 
    {
        cout << "Equation " << i + 1 << ": ";
        getline(cin, equations[i]);  // Get the full equation from the user
    }
    solver.convertStringsToMatrix(equations);  // Convert equations to matrix format
    solver.printMatrices();  // Print the matrices
    int determinant = solver.calculateDeterminant();
    cout << "Determinant of the coefficient matrix: " << determinant << endl;
    int i = 0, j = 0;
    cout << "\nEnter row number for minor : ";
    cin >> i;
    cout << "\nEnter column number for minor : ";
    cin >> j;
    int minorValue = solver.minor(i, j);  // Minor at position (0,0)
    cout << "Minor at position (i, j): " << minorValue << endl;
    int cofactorValue = solver.cofactor(i, j);  // Cofactor at position (0,0)
    cout << "Cofactor at position (i, j): " << cofactorValue << endl;
    
    return 0;
}
