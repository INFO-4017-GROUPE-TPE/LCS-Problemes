#include <iostream>
// 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
#include <vector>
using namespace std;
int max(int a, int b);
string display_sub_sequence(string sequence1, string sequence2, int **lcs_table);
string most_length_sub_sequence(string sequence1, string sequence2);

int main()
{

    string chaine1 = "DSGSHSRGSRHTRDADDFJNSJNFORNNRNKS";
    string chaine2 = "DATRGAGTSHSADDS";
    string sub_common_suite = most_length_sub_sequence(chaine1, chaine2);

    // Print LCS
    if (sub_common_suite != "") {
        cout <<"String 1: " + chaine1<< endl;
        cout <<"String 2: " + chaine2<< endl;
        cout <<"LCS: " + sub_common_suite<< endl;
        cout <<"LCS length: " + sub_common_suite.size()<< endl;
    }

    return 0;
}


int max(int a, int b){
    /* params: a integer value
       params: b integer value
       return the max between a and b
       */
    return (a>b) ? a:b;
}

string most_length_sub_sequence(string sequence1, string sequence2){


    if (sequence1.size() == 0 || sequence2.size() == 0){
        return "";
    }

    int **lcs_table = new int *[sequence1.size() + 1];

    for(int i =0; i< sequence1.size(); i++){
            lcs_table[i] = new int [sequence2.size() + 1];
        }

    for(int i =0; i < sequence1.size(); i++ ){
            lcs_table[i][0] = 0;
        }

    for(int j =0; j < sequence2.size(); j++ ){
            lcs_table[0][j] = 0;
            }

    for(int i =1; i < sequence1.size(); i++ ){

        for(int j =1; j < sequence2.size(); j++ ){
                if (sequence1[i - 1] == sequence2[j - 1]) {
                    lcs_table[i][j] = lcs_table[i - 1][j - 1] + 1;

                } else {
                    lcs_table[i][j] = max(lcs_table[i - 1][j], lcs_table[i][j - 1]);

                }

            }
    }

    return display_sub_sequence(sequence1, sequence2, lcs_table);

}

string display_sub_sequence(string sequence1, string sequence2, int  **lcs_table){
        string sub_lcs_table = "";

        int i = sequence1.size();
        int j = sequence2.size();
        while(i> 0 && j > 0){
            if (sequence1[i - 1] == sequence2[j - 1]) {
                   sub_lcs_table +=  sequence1[i - 1];
                   i--;
                   j--;

                }
                else if (lcs_table[i - 1][j] > lcs_table[i][j - 1]){
                        i--;
                    }
                else {
                    j--;

                }

        }


        return sub_lcs_table;
    }

