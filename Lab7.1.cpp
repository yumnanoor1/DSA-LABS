#include <iostream>

using namespace std;

class PlateStack {
private:
    int stack[100]; 
    int top;       
public:
    
    PlateStack() {
        top = -1;       }

{
        if (top < 99) {  
            top++;      
            stack[top] = plate;  
            cout << "Plate " << plate << " added to the stack.\n";
        } else {
            cout << "Stack is full! Can't add more plates.\n";
        }
    }

    // Remove the top plate from the stack
    void removePlate() {
        if (top >= 0) {  
            int topPlate = stack[top];  
            top--;       
            cout << "Plate " << topPlate << " removed from the stack.\n";
        } else {
            cout << "Stack is empty! Can't remove any plates.\n";
        }
    }

  
    void checkTopPlate() {
        if (top >= 0) {
            cout << "Top plate is: " << stack[top] << "\n";
        } else {
            cout << "Stack is empty! No top plate.\n";
        }
    }
};

int main() {
    PlateStack plates;

   
    plates.addPlate(1); 
    plates.addPlate(2); 
    plates.checkTopPlate(); 
    plates.addPlate(3); 

    plates.removePlate();
    plates.checkTopPlate();

    plates.removePlate(); 
    plates.removePlate(); 
    plates.removePlate();

    return 0;
}

