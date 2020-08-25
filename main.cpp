//p5 Sorts
//Rowan Briggs
//May 13, 2018
/* Description: add these, and get them to work
- void swap (int index1, int index2) { swaps two elements
 of the same array provided index1 and index2}

- void bubbleSort ( ) { uses the bubble sort algorithm
 implementation to sort the encapsulated array}

- void selectSort ( ) { uses the select sort algorithm
 implementation to sort the encapsulated array}

- void insertSort ( ) { uses the insert sort algorithm
 implementation to sort the encapsulated array}

- void deleteIndex (int index_to_delete) { deletes an
 element at index_to_delete, shifts-left elements on top of deleted element }

- void noDups ( ) { removes all duplicates from a sorted
 array, shifts-left elements on top of deleted elements }

- void  insert_in_order ( int number_to_insert ) { insert
 a number in the correct order, in an already sorted array }
 */

#include <iostream>
using namespace std;

class EncapsulatedArray{
private:
    int *array; //Dynamically allocated array
    int number_of_elements;
public:
    EncapsulatedArray(int size);
    void add(int number_to_add);
    void show();
    void insertFirst(int number_to_add);
    void deleteNumber(int number_to_delete);
    void bubbleSort();
    void showArray(int a[], int size);
    void selectSort();
    void insertSort();
    void swap(int index1,int index2);
    void deleteIndex(int index_to_delete);
    void noDups();
    void insert_in_order(int number_to_insert);
    void sort();
};

EncapsulatedArray::EncapsulatedArray(int size){
    array = new int[size]; // Dyncamically allocated array
    number_of_elements = 0;
}

void EncapsulatedArray::deleteNumber(int number_to_delete){
    for (int i = 0; i < number_of_elements-1; i++){
        if(array[i]==number_to_delete){
            for(int j = i; j < number_of_elements-1; j++){
                array[j]=array[j+1];
            }
            number_of_elements--;
        }
    }
}

void EncapsulatedArray::insertFirst(int number_to_add){
    for (int i = number_of_elements-1; i >= 0; i--)
        array[i+1] = array[i];
    array[0] = number_to_add;

    number_of_elements++;
}

void EncapsulatedArray::sort(){
    int temp = 0;
    for (int i = number_of_elements; i > 0; i--){

        for(int j = 0; j < number_of_elements; j++){
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void EncapsulatedArray::bubbleSort(){
    for (int i = 0; i < number_of_elements - 1; i++){
        for (int j = 0; j < number_of_elements - (i+1); j++){
            if (array[j] > array[j+1]){
                swap(j,j+1);
            }
        }
    }
}

void EncapsulatedArray::add(int number_to_add){
    array[number_of_elements] = number_to_add;
    number_of_elements++;
}

//show arrays as {9, 101, 9}
void EncapsulatedArray::show(){
    if(number_of_elements == 1){
        cout << "array = {" << array[0] << "}\n ";
        return;
    }
    int i;
    cout << "array = {";
    for(i = 0; i < number_of_elements-1;i++){
        cout << array[i] << ", ";
    }
    cout << array[i] << "}\n ";
}

void EncapsulatedArray::selectSort(){
    int min, min_index;
    for (int current_index = 0; current_index < number_of_elements - 1; current_index++){
        min_index = current_index;

        for(int i = current_index+1; i < number_of_elements; i++){
            if(array[i] < array[min_index]){
                min_index = i;
            }
        }
        swap(current_index, min_index); //swap is outside the loop
    }
}

void EncapsulatedArray::swap(int index1, int index2){
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void EncapsulatedArray::insertSort(){
    int in, out, temp;
    for (out = 1; out < number_of_elements; out++){
        in = out;
        temp = array[in]; // 1)
        while(in > 0 && array[in - 1] > temp) { // 2)
            //^^while doesn't happen much for partially sorted array
            array[in] = array[in - 1]; // 3)
            in--;
        }
        array[in] = temp; // 4)
    }
}

void EncapsulatedArray::deleteIndex(int index_to_delete){
    for (int i = 0; i < number_of_elements-1; i++){
        if(i == index_to_delete){
            for(int j = i; j < number_of_elements-1; j++){
                array[j]=array[j+1];
            }
            number_of_elements--;
        }
    }
}

void EncapsulatedArray::noDups(){
    for (int j = number_of_elements - 1; j > 0; j--){
        for (int i = 0; i < j; i++){
            if (array[i] == array [j]){
                array[j] = array[j+1];
                number_of_elements--;
            }
        }
    }
}

void EncapsulatedArray::insert_in_order(int number_to_insert) {
    //for (int i = number_of_elements-1; i >= 0; i--)
    //    array[i+1] = array[i];
    //array[0] = number_to_add;

    //number_of_elements++;

    //this assumes that the array has already been sorted, so we do not need the code to sort it
    int index;
    for (int i = 0; i < number_of_elements; i++){
        if (array[i] > number_to_insert) {
            index = i;
            break;
        }
    }
    for (int i = number_of_elements-1; i >= index; i--){
        array[i+1] = array[i];
    }
    array[index] = number_to_insert;
    number_of_elements++;
}


int main() {
    //test for bubble sort
    EncapsulatedArray anArray(6);
    anArray.add(3);
    anArray.add(8);
    anArray.add(7);
    anArray.add(5);
    anArray.insertFirst(9);
    anArray.add(4);
    anArray.show();
    anArray.bubbleSort();
    anArray.show();

    //test for selection sort
    EncapsulatedArray secondArray(6);
    secondArray.add(3);
    secondArray.add(8);
    secondArray.add(7);
    secondArray.add(5);
    secondArray.insertFirst(9);
    secondArray.add(4);
    secondArray.show();
    secondArray.selectSort();
    secondArray.show();

    //test for insert sort
    EncapsulatedArray thirdArray(6);
    thirdArray.add(3);
    thirdArray.add(8);
    thirdArray.add(7);
    thirdArray.add(5);
    thirdArray.insertFirst(9);
    thirdArray.add(4);
    thirdArray.show();
    thirdArray.insertSort();
    thirdArray.show();
    thirdArray.deleteIndex(3);
    thirdArray.show();

    //testing the noDups part of the code
    thirdArray.add(4);
    thirdArray.show();
    thirdArray.noDups();
    thirdArray.show();
    thirdArray.insertFirst(8);
    thirdArray.show();
    thirdArray.noDups();
    thirdArray.show();

    //testing for the insert_in_order
    thirdArray.insertSort();
    thirdArray.show();
    thirdArray.insert_in_order(7);
    thirdArray.show();
    thirdArray.insert_in_order(6);
    thirdArray.show();
}

/* Output
array = {9, 3, 8, 7, 5, 4}
 array = {3, 4, 5, 7, 8, 9}
 array = {9, 3, 8, 7, 5, 4}
 array = {3, 4, 5, 7, 8, 9}
 array = {9, 3, 8, 7, 5, 4}
 array = {3, 4, 5, 7, 8, 9}
 array = {3, 4, 5, 8, 9}
 array = {3, 4, 5, 8, 9, 4}
 array = {3, 4, 5, 8, 9}
 array = {8, 3, 4, 5, 8, 9}
 array = {8, 3, 4, 5, 9}
 array = {3, 4, 5, 8, 9}
 array = {3, 4, 5, 7, 8, 9}
 array = {3, 4, 5, 6, 7, 8, 9}

Process finished with exit code 0
 */