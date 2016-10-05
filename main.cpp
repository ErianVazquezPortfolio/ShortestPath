/* 
 * File:   main.cpp
 * Author: Erian Vazquez
 *
 * Created on April 22, 2015, 8:00 PM
 */

#include <cstdlib>
#include<iostream>
#include <algorithm>
#include <sstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int size;// first three cin to store the first 3 main values 
    cin>>size;
    int edgeCount;
    cin>>edgeCount;
    int querieCount;
    cin>>querieCount;
    
    int max = (2147483644/2); //make my "infinite" variable

    int weightMartix[size+1][size+1]; //make my two tables/matrixes
    int pathMartix[size+1][size+1];
    
    for(int i = 0; i <= size; i++) { // set default everything to max and path to normal
	for(int j = 0; j <= size; j++) {
            weightMartix[i][j] = max;
            pathMartix[i][j] = j;
        }
    }
    
    for(int i = 0; i <= size; i++) { // set diagonal to 0
        weightMartix[i][i] = 0;
    }
    
    for(int i = 1; i <= edgeCount; i++){ //take in inputs and set weight of path
        int start;
        cin>>start;
        int end;
        cin>>end;
        int weight;
        cin>>weight;
        
        weightMartix[start][end] = weight;
        pathMartix[start][end] = end;
    }
    
    for(int k = 1; k <= size; k++) {  // go through adding through paths and set the path table
	for(int i = 1; i <= size; i++) {
            for(int j = 1; j <= size; j++) {
                if(weightMartix[i][k] != max && weightMartix[k][j] != max){ // we need to make sure that we can get to the end so if either are "infinite" then don't even try 
                    if(weightMartix[i][k]+weightMartix[k][j] < weightMartix[i][j]){
                        weightMartix[i][j] = weightMartix[i][k]+weightMartix[k][j]; 
                        pathMartix[i][j] = pathMartix[i][k]; // path 
                    }                   
                }
            }
        }
    }
    
    for(int i = 1; i <= querieCount; i++){ // go through querie count 
        int start;
        cin>>start;
        int end;
        cin>>end;
        
        if(weightMartix[start][end] == max){ // if the value is "infinite" then there is no path
            cout << "NO PATH" << endl;
        } else if(start == end){ // if they are equal the weight is 0 and the path is it self
            cout << "cost = 0" << endl;
            cout << start << "-" << end << endl;
        } else {
            string outputString; // turn input in the start of the path 
            std::stringstream out;
            out << start;
            outputString.append(out.str());
            int tempStart = start;
            int tempEnd = end;
            cout << "cost = " << weightMartix[start][end] << endl; // print cost
                while(tempStart != tempEnd){ // loop through appending the path
                    tempStart = pathMartix[tempStart][tempEnd];
                    outputString.append("-");
                    std::stringstream out;
                    out << tempStart;
                    outputString.append(out.str());
                }
                
                cout << outputString << endl; // print path
        }
    }
    
    return 0;
}

