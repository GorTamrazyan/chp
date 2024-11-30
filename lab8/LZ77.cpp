#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

class LZ77 {
    public:
        LZ77(int bufferSize) {
            this->bufferSize = bufferSize;
        }

        void compress(string& text) {

            int n = text.length();

            for (int i = 0; i < n;) {
                int maxMatchLength = 0;
                int matchBack = 0;

                int start = max(0, i - bufferSize);

                for (int j = start; j < i; j++) {
                    int matchLength = 0;

                    while (j + matchLength < i && i + matchLength < n &&
                            text[j + matchLength] == text[i + matchLength]) {
                        matchLength++;
                    }

                    if (matchLength > maxMatchLength) {
                        maxMatchLength = matchLength;
                        matchBack = i - j;
                    }
                }

                char nextChar = (i + maxMatchLength < n) ? text[i + maxMatchLength] : '\0';
                tokens.push_back(Token(matchBack, maxMatchLength, nextChar));

                i += maxMatchLength + 1;

            }
            
        }

        string decompress() {
            string result;

            for (const auto& token : tokens) {
                int start = result.size() - token.back;

                for (int i = 0; i < token.length; i++)
                    result += result[start + i];

                if (token.next != '\0')
                    result += token.next;
            }
            return result;
        }
        
        void printTokens() {
            for (const auto& token : tokens)
                token.print();
        }
        
    private:
        struct Token {
            int back;
            int length;
            char next;

            Token(int b, int l, char n) : back(b), length(l), next(n){}
            void print() const {
                cout << "(" << back << ", " << length << ", " << next << ")" << endl;
            }
        };
        vector<Token> tokens;
        int bufferSize;
};