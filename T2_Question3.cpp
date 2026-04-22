#include <iostream>
using namespace std;

void drawBox(int w);
void drawFullLine(int w);
void drawEmptyLine(int w);

int main() {
    int width;
    cout << "\nEnter the side of the square box (1-16): ";
    cin >> width;

    drawBox(width);

    return 0;
}

void drawBox(int w) {
    if(w < 1) return;

    drawFullLine(w); // top line

    for(int i = 0; i < w - 2; i++) {
        drawEmptyLine(w); // middle hollow lines
    }

    if(w > 1)
        drawFullLine(w); // bottom line
}

void drawFullLine(int w) {
    for(int i = 0; i < w; i++) {
        cout << "* ";
    }
    cout << endl;
}

void drawEmptyLine(int w) {
    cout << "* ";
    for(int i = 0; i < w - 2; i++) {
        cout << "  ";
    }
    if(w > 1) cout << "*";
    cout << endl;
}
