//
// Created by kougianosg on 03-Sep-18.
//

#include <iostream>
#include <seqan/align.h>

using namespace seqan;

int main()
{
    // Computes the 3 best local alignments of the two AminoAcid sequences

    Align<String<AminoAcid> > ali;
    resize(rows(ali), 2);
    assignSource(row(ali, 0), "PNCFDAKQRTASRPL");
    assignSource(row(ali, 1), "CFDKQKNNRTATRDTA");

    Score<int> sc(3, -2, -1, -5);
    unsigned count = 0;
    LocalAlignmentEnumerator<Score<int>, Unbanded> enumerator(sc);
    while (nextLocalAlignment(ali, enumerator) && count < 3)
    {
        std::cout << "Score = " << getScore(enumerator) << std::endl;
        std::cout << ali;
        ++count;
    }


    return 0;
}