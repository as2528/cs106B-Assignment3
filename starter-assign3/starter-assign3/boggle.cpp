/*
 * TODO: remove and replace this file header comment
 * You will edit and turn in this file.
 * Remove starter comments and add your own
 * comments on each function and on complex code sections.
 */
#include <iostream>    // for cout, endl
#include <string>      // for string class
#include "backtracking.h"
#include "gridlocation.h"
#include "grid.h"
#include "set.h"
#include "lexicon.h"
#include "testing/SimpleTest.h"
using namespace std;

/*
 * This function takes the string, and finds the score it deserves recursively.
 * Input: String.
 * Output: An integer showing the score the string deserves.
 */
int points(string str) {
    if(str.length()<=3){
        return 0;
    }
    if(str.length()>3){
        return 1+points(str.substr(1));
    }
    else{
        return 0;}
}
/*
int toSearch(Grid<char>&board,Grid<bool>locations,Lexicon&lex, Set<string>&words, int row, int column, string word){
    int totalPoints = 0;
    if(lex.contains(word)&&!words.contains(word)){//base case
        words.add(word);
        return points(word);
    }
    if(words.contains(word)){
        return 0;
    }
    if(locations.inBounds(row+1,column)&&!locations.get(row+1,column)&&lex.containsPrefix(word+(board.get(row+1, column)))){
      locations.set(row+1,column,true);
      totalPoints+=toSearch(board,locations, lex,words, row+1, column, word+board.get(row+1, column));
        //then i can consider this a word
    }
    if(locations.inBounds(row+1,column+1)&&!locations.get(row+1,column+1)&&lex.containsPrefix(word+(board.get(row+1, column+1)))){
      locations.set(row+1,column+1,true);
      totalPoints+=toSearch(board,locations, lex,words, row+1, column+1, word+board.get(row+1, column+1));
        //then i can consider this a word
    }
    if(locations.inBounds(row,column+1)&&!locations.get(row,column+1)&&lex.containsPrefix(word+(board.get(row, column+1)))){
      locations.set(row,column+1,true);
      totalPoints+=toSearch(board,locations, lex,words, row, column+1, word+board.get(row, column+1));
        //then i can consider this a word
    }
    if(locations.inBounds(row-1,column)&&!locations.get(row-1,column)&&lex.containsPrefix(word+(board.get(row-1, column)))){
      locations.set(row-1,column,true);
      totalPoints+=toSearch(board,locations, lex,words, row-1, column, word+board.get(row-1, column));
        //then i can consider this a word
    }
    if(locations.inBounds(row-1,column-1)&&!locations.get(row-1,column-1)&&lex.containsPrefix(word+(board.get(row-1, column-1)))){
      locations.set(row-1,column-1,true);
      totalPoints+=toSearch(board,locations, lex,words, row-1, column-1, word+board.get(row-1, column-1));
        //then i can consider this a word
    }
    if(locations.inBounds(row,column-1)&&!locations.get(row,column-1)&&lex.containsPrefix(word+(board.get(row, column-1)))){
      locations.set(row,column-1,true);
      totalPoints+=toSearch(board,locations, lex,words, row, column-1, word+board.get(row, column-1));
        //then i can consider this a word
    }
    if(locations.inBounds(row+1,column-1)&&!locations.get(row+1,column-1)&&lex.containsPrefix(word+(board.get(row+1, column-1)))){
      locations.set(row+1,column-1,true);
      totalPoints+=toSearch(board,locations, lex,words, row+1, column-1, word+board.get(row+1, column-1));
        //then i can consider this a word
    }
    if(locations.inBounds(row-1,column+1)&&!locations.get(row-1,column+1)&&lex.containsPrefix(word+(board.get(row-1, column+1)))){
      locations.set(row-1,column+1,true);
      totalPoints+=toSearch(board,locations, lex,words, row-1, column+1, word+board.get(row-1, column+1));
        //then i can consider this a word
    }




    return(totalPoints);

}
*/
Set<GridLocation> generateValidMoves(Grid<char>& maze, GridLocation cur) {
    Set<GridLocation> neighbors;

    GridLocation temp;

for(int k=0; k!=maze.size();k++){
    if(maze.inBounds(cur.row-1,cur.col)&&maze[cur.row-1][cur.col]){
        temp = cur;
        temp.row--;
        neighbors.add(temp);
        }
    if(maze.inBounds(cur.row+1,cur.col)&&maze[cur.row+1][cur.col]){
        temp = cur;
        temp.row++;
        neighbors.add(temp);
        }
    if(maze.inBounds(cur.row,cur.col-1)&&maze[cur.row][cur.col-1]){
        temp = cur;
        temp.col--;
        neighbors.add(temp);
        }
    if(maze.inBounds(cur.row,cur.col+1)&&maze[cur.row][cur.col+1]){
        temp = cur;
        temp.col++;
        neighbors.add(temp);
        }
    if(maze.inBounds(cur.row+1,cur.col+1)&&maze[cur.row+1][cur.col+1]){
        temp = cur;
        temp.col++;
        temp.row++;
        neighbors.add(temp);
        }
    if(maze.inBounds(cur.row+1,cur.col-1)&&maze[cur.row+1][cur.col-1]){
        temp = cur;
        temp.col--;
        temp.row++;
        neighbors.add(temp);
        }
    if(maze.inBounds(cur.row-1,cur.col+1)&&maze[cur.row-1][cur.col+1]){
        temp = cur;
        temp.col++;
        temp.row--;
        neighbors.add(temp);
        }
    if(maze.inBounds(cur.row-1,cur.col-1)&&maze[cur.row-1][cur.col-1]){
        temp = cur;
        temp.col--;
        temp.row--;
        neighbors.add(temp);
        }
    }
    return neighbors;
}


Grid<bool> haveVisited(Grid<bool>locations,GridLocation currentPosition){
    GridLocation startPosition = {0,0};
    locations.set(currentPosition,true);
    locations.set(startPosition,true);
    return locations;
}

Set<string> recursiveSolver(Grid<char>& board, Lexicon& lex,string word,GridLocation currentPosition, Grid<bool>locations, Set<GridLocation>allNeighbors,Set<string>previousWords){
   // int points =0;
 //   int rows=0;
   // int columns=0;

    string temp=word;
//Current errors. Will not pick up the first c in the czar test case. Will not go back if there is an issue with the current choice. Will find one word and end.
//Current progress. Will check neighbors properly. Will record where it has been, will also recurse and toss away impossible moves from current position.
//Should return the set of words instead of a single word and score all the possible words. Is better than a single word.

    //currentPosition={rows,columns};
    if(lex.contains(word)){
        previousWords+=word;
        return previousWords;
    }
    if(!allNeighbors.isEmpty()&&!locations.get(allNeighbors.first())&&lex.containsPrefix(temp+=((board.get(allNeighbors.first()))))){
        word+=(board.get(allNeighbors.first()));
        currentPosition = allNeighbors.first();
        allNeighbors.clear();
        locations = haveVisited(locations,currentPosition);
        return recursiveSolver(board,lex,word,currentPosition,locations,generateValidMoves(board,currentPosition),previousWords);
    }
    if(!allNeighbors.isEmpty()){
        allNeighbors.remove(allNeighbors.first());
        return recursiveSolver(board,lex,word,currentPosition,locations,allNeighbors,previousWords);
    }
    else{
        return previousWords;
    }



/*
    for(rows=0;rows!=board.numRows();rows++){
        for(columns=0;columns!=board.numCols();columns++){
            currentPosition={rows,columns};
            allNeighbors = generateValidMoves(board,currentPosition);
            while(!allNeighbors.isEmpty()){
                if(lex.containsPrefix(word+board.get(allNeighbors.first()))){
                    word = word+board.get(allNeighbors.first());
                    haveVisited(locations,rows,columns);
                    allNeighbors.remove(allNeighbors.first());
                }
                else if(!lex.containsPrefix(word+board.get(allNeighbors.first()))){
                     haveVisited(locations,rows,columns);
                     allNeighbors.remove(allNeighbors.first());
                }
            }
        }
    }*/
}

/*
 * TODO: Replace this comment with a descriptive function
 * header comment.
 */
int scoreBoard(Grid<char>& board, Lexicon& lex) {//This function will backtrace until it finds the possible words on boggle board
  /* TODO: Implement this function.
    int result=0;
    Set<string>words;

    for(int rowsToTry=0;rowsToTry<board.numRows();rowsToTry++){//All neighbors of the cube
        for(int columnsToTry=0;columnsToTry<board.numCols();columnsToTry++){
           Grid<bool>locations(board.numRows(), board.numCols(), false);
           result += toSearch(board,locations, lex, words,rowsToTry, columnsToTry, string()+(board.get(rowsToTry,columnsToTry)));


        }
    }


    return result;*/
    int result =0;
    string word = "";
    GridLocation startPosition ={0,0};
    Grid<bool>locations(board.numRows(), board.numCols(), false);
    Set<string>previousWords;
    Set<string>finalWord = recursiveSolver(board, lex,word,startPosition,locations,generateValidMoves(board,startPosition),previousWords);

    while(!finalWord.isEmpty()){
        result += points(finalWord.first());
        finalWord.remove(finalWord.first());
    }
    return result;
}


//https://github.com/heavy3/programming-abstractions/blob/master/09-recursion-backtracking/readerEx.09.16/Boggle.cpp

/* * * * * * Test Cases * * * * * */

/* Test helper function to return shared copy of Lexicon. Use to
 * avoid (expensive) re-load of word list on each test case. */
static Lexicon& sharedLexicon() {
    static Lexicon lex("res/EnglishWords.txt");
    return lex;
}

PROVIDED_TEST("Load shared Lexicon, confirm number of words") {
    Lexicon lex = sharedLexicon();
    EXPECT_EQUAL(lex.size(), 127145);
}

PROVIDED_TEST("Test point scoring") {
    EXPECT_EQUAL(points("and"), 0);
    EXPECT_EQUAL(points("quad"), 1);
    EXPECT_EQUAL(points("quint"), 2);
    EXPECT_EQUAL(points("sextet"), 3);
    EXPECT_EQUAL(points("seventh"), 4);
    EXPECT_EQUAL(points("supercomputer"), 10);
}

PROVIDED_TEST("Test scoreBoard, board contains no words, score of zero") {
    Grid<char> board = {{'B','C','D','F'}, //no vowels, no words
                        {'G','H','J','K'},
                        {'L','M','N','P'},
                        {'Q','R','S','T'}};
    EXPECT_EQUAL(scoreBoard(board, sharedLexicon()), 0);
}

PROVIDED_TEST("Test scoreBoard, board contains one word, score of 1") {
    Grid<char> board = {{'C','_','_','_'},
                        {'Z','_','_','_'},
                        {'_','A','_','_'},
                        {'_','_','R','_'}};
    EXPECT_EQUAL(scoreBoard(board, sharedLexicon()), 1);
}

PROVIDED_TEST("Test scoreBoard, alternate paths for same word, still score of 1") {
    Grid<char> board = {{'C','C','_','_'},
                        {'C','Z','C','_'},
                        {'_','A','_','_'},
                        {'R','_','R','_'}};
    EXPECT_EQUAL(scoreBoard(board, sharedLexicon()), 1);
}

PROVIDED_TEST("Test scoreBoard, small number of words in corner of board") {
    Grid<char> board = {{'L','I','_','_'},
                        {'M','E','_','_'},
                        {'_','S','_','_'},
                        {'_','_','_','_'}};
    Set<string> words = {"SMILE", "LIMES", "MILES", "MILE", "MIES", "LIME", "LIES", "ELMS", "SEMI"};

    EXPECT_EQUAL(scoreBoard(board, sharedLexicon()),  2 + 2 + 2 + 1 + 1 + 1 + 1 + 1 + 1);
}

PROVIDED_TEST("Test scoreBoard, full board, small number of words") {
    Grid<char> board = {{'E','Z','R','R'},
                        {'O','H','I','O'},
                        {'N','J','I','H'},
                        {'Y','A','H','O'}};
    Set<string> words = { "HORIZON", "OHIA", "ORZO", "JOHN", "HAJI"};

    EXPECT_EQUAL(scoreBoard(board, sharedLexicon()), 4 + 1 + 1 + 1 + 1);
}

PROVIDED_TEST("Test scoreBoard, full board, medium number of words") {
    Grid<char> board = {{'O','T','H','X'},
                        {'T','H','T','P'},
                        {'S','S','F','E'},
                        {'N','A','L','T'}};

    EXPECT_EQUAL(scoreBoard(board, sharedLexicon()), 76);
}

PROVIDED_TEST("Test scoreBoard, full board, large number of words") {
    Grid<char> board = {{'E','A','A','R'},
                        {'L','V','T','S'},
                        {'R','A','A','N'},
                        {'O','I','S','E'}};

    EXPECT_EQUAL(scoreBoard(board, sharedLexicon()), 234);
}
