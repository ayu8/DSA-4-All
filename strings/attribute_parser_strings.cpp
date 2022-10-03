#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> getQuery(vector<string> query) {
    int l, st;
    string buf;
    query.clear();
    getline(cin, buf);
    l = buf.length();
    st = 0;
    for (int i = 0; i < l; i++) {
        if (buf[i] == '.') {
            query.push_back(buf.substr(st, i - st));
            st = i + 1;
        }
        else if (buf[i] == '~') {
            query.push_back(buf.substr(st, i - st));
            st = i;
            query.push_back(buf.substr(st, l - st));
        }
    }
    return query;
}

void resolveQuery(vector<string> query, vector<string> listing) {
    int lQ = query.size();
    int lL = listing.size();
    int iQ = 0;
    int listS, attL, lineL;
    vector<string> currentTagList;
    for (int j = 0; j < lL; j++) {
        if (listing[j][1] == '/') { 
            currentTagList.pop_back(); //we remove last tag from the list, valid listing means, we dont need to check what tag it is
        }
        else {
            int k = 1;
            while (listing[j][k] != ' ' && listing[j][k] != '>') {
                k++;
            }
            string newTag = listing[j].substr(1, k-1);
            currentTagList.push_back(newTag);
            if (newTag == query[iQ]) {
                iQ++;
                if (query[iQ][0] == '~') { //we are on the attribute query, our value is on this line, or nowhere
                    listS = currentTagList.size();
                    for (int i = 0; i < listS; i++) {
                        if (currentTagList[i] != query[i]) {
                            cout << "Not Found!" << endl;
                            return;
                        }
                    }
                    attL = query[iQ].length() - 1; //don't count '~'
                    lineL = listing[j].length();
                    for (int i = 1; i + attL < lineL; i++) {
                        if (listing[j].substr(i, attL + 1) == ' ' + query[iQ].substr(1, attL)) {
                            k = i + attL;
                            while (listing[j][k] != '"') {
                                k++;
                            }
                            k++;
                            while (listing[j][k] != '"') {
                                cout << listing[j][k];
                                k++;
                            }
                            cout << endl;
                            return;
                        }
                    }
                    cout << "Not Found!" << endl; //since we didn't find <attribute> on this line we can safetly return
                    return;
                }
            }
        }
    }
    cout << "Not Found!" << endl; //if we gone through the whole list without finding out tag we do not forget to print the result
    return;
}

//Question Link:
//https://www.hackerrank.com/challenges/attribute-parser/problem?isFullScreen=true
