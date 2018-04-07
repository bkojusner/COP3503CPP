/*
 * Blas Kojusner
 * 10/2/17
 * Programming Assignment #1
 */
#include <iostream>
using namespace std;

//Function to generate the magic square
void makeSquares(int size) {

	//Initializing array
	int magicSquare [size][size];

	//Setting array values to 0
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			magicSquare[i][j] = 0;
		}
	}

//Comment for Square #1
	cout<<"\nMagic Square #1 is: \n";
	cout<<"\n";

	// Initializing variables for position of number 1
    int i = 0;
    int j = size/2;
    int dim = size * size;

    // Loop following Siamese Method rules
    for(int num = 1; num <= dim; num++){
    	magicSquare [i][j] = num;
    	i--;
    	j++;

    	//If statements to make sure conditions are met
    	if(num % size == 0){
    		i += 2;
    	    j--;
    	}
    	else if(i < 0){
    		i += size;
    	}
    	else if(j == size){
    		j -= size;
    	}
    	else{
    		continue;
    	}
    }

    // Print magic square
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        	cout<<"  "<<magicSquare[i][j];
        cout<<"\n";
    }

	//Checking sums of rows of magicSquare
	cout<<"\nChecking the sums of every row:      ";
	int sum;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			sum += magicSquare[i][j];
		}
		cout<<sum<<" ";
		sum = 0;
		continue;
	}

	//Checking sums of columns of magicSquare
	cout<<"\nChecking the sums of every column:   ";
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			sum += magicSquare[j][i];
		}
		cout<<sum<<" ";
		sum = 0;
		continue;
	}

	//Checking sums of diagonals of magicSquare
	cout<<"\nChecking the sums of every diagonal: ";
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			sum += magicSquare[i][j];
			break;
		}
	}

	cout<<sum<<" ";
	sum = 0;

	for(int i = 0; i < size; i++){
		for(int j = size - 1; j > 0; j--){
			sum += magicSquare[i][j];
			break;
		}
	}
	cout<<sum<<" ";
	sum = 0;
	cout<<"\n";


//Comment for Square #2
	cout<<"Magic Square #2 is: \n";
	cout<<"\n";

	//for loops changing the last row with the first one
	for(int i = size - 1; i < size; i++){
		for(int j = 0; j < size; j++){
			cout<<"  "<<magicSquare[i][j];
		}
		cout<<"\n";
	}

	for(int i = 1; i <= size - 2; i++){
			for(int j = 0; j < size; j++){
				cout<<"  "<<magicSquare[i][j];
			}
		cout<<"\n";
		}

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cout<<"  "<<magicSquare[i][j];
		}
		cout<<"\n";
		break;
	}

	//Checking sums of rows of magicSquare
	cout<<"\nChecking the sums of every row:      ";
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			sum += magicSquare[i][j];
		}
		cout<<sum<<" ";
		sum = 0;
		continue;
	}

	//Checking sums of columns of magicSquare
	cout<<"\nChecking the sums of every column:   ";
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			sum += magicSquare[j][i];
		}
		cout<<sum<<" ";
		sum = 0;
		continue;
	}

	//Checking sums of diagonals of magicSquare
	cout<<"\nChecking the sums of every diagonal: ";
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			sum += magicSquare[i][j];
			break;
		}
	}

	cout<<sum<<" ";
	sum = 0;

	for(int i = 0; i < size; i++){
		for(int j = size - 1; j > 0; j--){
			sum += magicSquare[i][j];
			break;
		}
	}
	cout<<sum<<" ";
	sum = 0;
	cout<<"\n";


//Comment for Square #3
	cout<<"Magic Square #3 is: \n";
	cout<<"\n";

	//for loops changing the diagonals of the array
	for(int i = size - 1; i < size; i++){
		for(int j = 0; j < size; j++){
			cout<<"  "<<magicSquare[j][i];
		}
		cout<<"\n";
	}

	for(int i = 1; i <= size - 2; i++){
			for(int j = 0; j < size; j++){
				cout<<"  "<<magicSquare[j][i];
			}
		cout<<"\n";
		}

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cout<<"  "<<magicSquare[j][i];
		}
		cout<<"\n";
		break;
	}

	//Checking sums of rows of magicSquare
	cout<<"\nChecking the sums of every row:      ";
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			sum += magicSquare[i][j];
		}
		cout<<sum<<" ";
		sum = 0;
		continue;
	}

	//Checking sums of columns of magicSquare
	cout<<"\nChecking the sums of every column:   ";
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			sum += magicSquare[j][i];
		}
		cout<<sum<<" ";
		sum = 0;
		continue;
	}

	//Checking sums of diagonals of magicSquare
	cout<<"\nChecking the sums of every diagonal: ";
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			sum += magicSquare[i][j];
			break;
		}
	}

	cout<<sum<<" ";
	sum = 0;

	for(int i = 0; i < size; i++){
		for(int j = size - 1; j > 0; j--){
			sum += magicSquare[i][j];
			break;
		}
	}
	cout<<sum<<" ";
	sum = 0;
	cout<<"\n";


//Comment for Square #4
	cout<<"Magic Square #4 is: \n";
	cout<<"\n";

	//for loop changing the last row with the first one
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cout<<"  "<<magicSquare[j][i];
		}
		cout<<"\n";
	}

	//Checking sums of rows of magicSquare
	cout<<"\nChecking the sums of every row:      ";
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			sum += magicSquare[i][j];
		}
		cout<<sum<<" ";
		sum = 0;
		continue;
	}

	//Checking sums of columns of magicSquare
	cout<<"\nChecking the sums of every column:   ";
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			sum += magicSquare[j][i];
		}
		cout<<sum<<" ";
		sum = 0;
		continue;
	}

	//Checking sums of diagonals of magicSquare
	cout<<"\nChecking the sums of every diagonal: ";
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			sum += magicSquare[i][j];
			break;
		}
	}
	cout<<sum<<" ";
	sum = 0;
	for(int i = 0; i < size; i++){
		for(int j = size - 1; j > 0; j--){
			sum += magicSquare[i][j];
			break;
		}
	}
	cout<<sum<<" ";
	sum = 0;
	cout<<"\n";

//Comment for Square #5
	cout<<"Magic Square #5 is: \n";
	cout<<"\n";

	//for loop changing the diagonals of the array
	for(int i = size - 1; i >= 0; i--){
		for(int j = size - 1; j >= 0; j--){
			cout<<"  "<<magicSquare[i][j];
		}
		cout<<"\n";
	}

	//Checking sums of rows of magicSquare
	cout<<"\nChecking the sums of every row:      ";
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			sum += magicSquare[i][j];
		}
		cout<<sum<<" ";
		sum = 0;
		continue;
	}
	//Checking sums of columns of magicSquare
	cout<<"\nChecking the sums of every column:   ";
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			sum += magicSquare[j][i];
		}
		cout<<sum<<" ";
		sum = 0;
		continue;
	}
	//Checking sums of diagonals of magicSquare
	cout<<"\nChecking the sums of every diagonal: ";
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			sum += magicSquare[i][j];
			break;
		}
	}
	cout<<sum<<" ";
	sum = 0;
	for(int i = 0; i < size; i++){
		for(int j = size - 1; j > 0; j--){
			sum += magicSquare[i][j];
			break;
		}
	}
	cout<<sum<<" ";
	sum = 0;
	cout<<"\n";
}

int main() {
	//prompt user for input
	cout<<"Enter the size of a magic square: ";
	int size;
	cin>>size;

	//Makes sure size is in range & is odd
	if(size < 3 || size > 15 || size % 2 == 0){
		cout<<"Please try inputting an odd number between 3 and 15";
		return 0;
	}
	else
	//Print out function that makes Magic Square
	makeSquares (size);

	return 0;
}
