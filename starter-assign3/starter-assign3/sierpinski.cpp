/*
 * TODO: remove and replace this file header comment
 * You will edit and turn in this file.
 * Remove starter comments and add your own
 * comments on each function and on complex code sections.
 */
#include <iostream>    // for cout, endl
#include "recursion.h"
#include "testing/SimpleTest.h"
using namespace std;

/*
 * This function draws a filled, black triangle on the provided GWindow
 * that is defined by the corner GPoints one, two, and three. This
 * function has been provided for you and does not need to be modified.
 */
void fillBlackTriangle(GWindow& window, GPoint one, GPoint two, GPoint three) {
    window.setColor("black");
    window.fillPolygon( {one, two, three} );
}

/*
 * Input: order of triangle
 * Output: Number of triangles to draw.Calculated recursively.
 */
int drawSierpinskiTriangle(GWindow& window, GPoint one, GPoint two, GPoint three, int order) {
    if(order==0){
        return 1;
    }
    if (order!=0){
        return 3 * drawSierpinskiTriangle(window, one, two, three, order-1);
    }
   else{
        return 1;
    }
    /* Previously submitted example by a Stanford Student, tried to get function to draw using ut
    drawTriangle(gw, length, p0);
    if (order == 0) return;
    else {
        GPoint p1 = gw.drawPolarLine(p0, length / 2, 60);
        GPoint p2 = gw.drawPolarLine(p0, length / 2, 0);
        gw.drawLine(p1, p2);
        drawSierpinskiTriangle(gw, length / 2, order - 1, p0);
        drawSierpinskiTriangle(gw, length / 2, order - 1, p1);
        drawSierpinskiTriangle(gw, length / 2, order - 1, p2);
    }*/
}


/* * * * * * Test Cases * * * * * */

/*
 * Do not modify the code beyond this line! There are no
 * unit tests for this problem. You should do all testing
 * via the interactive demo.
 */

PROVIDED_TEST("Test fractal drawing interactively using graphical demo") {
    runInteractiveDemo();
}

