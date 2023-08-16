#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

bool isValidWord(const string& word, const unordered_set<string>& wordDict) {
    return wordDict.count(word) > 0;
}

vector<string> findWordPath(const string& startWord, const string& endWord, const unordered_set<string>& wordDict) {
    queue<string> wordQueue;
    unordered_set<string> visited;
    unordered_map<string, string> parent;
    vector<string> wordPath;

    wordQueue.push(startWord);
    visited.insert(startWord);

    while (!wordQueue.empty()) {
        string currentWord = wordQueue.front();
        wordQueue.pop();

        if (currentWord == endWord) {
            // Reconstruct the word path
            string word = endWord;
            while (word != startWord) {
                wordPath.push_back(word);
                word = parent[word];
            }
            wordPath.push_back(startWord);
            reverse(wordPath.begin(), wordPath.end());
            break;
        }

        // Generate all possible next words with one letter difference
        for (int i = 0; i < currentWord.length(); i++) {
            string tempWord = currentWord;
            for (char c = 'a'; c <= 'z'; c++) {
                tempWord[i] = c;
                if (isValidWord(tempWord, wordDict) && !visited.count(tempWord)) {
                    visited.insert(tempWord);
                    wordQueue.push(tempWord);
                    parent[tempWord] = currentWord;
                }
            }
        }
    }

    return wordPath;
}

int main() {
    unordered_set<string> wordDict = { "hot", "dot", "dog", "lot", "log", "cog" };
    string startWord = "hit";
    string endWord = "cog";

    vector<string> wordPath = findWordPath(startWord, endWord, wordDict);

    if (wordPath.empty()) {
        cout << "No valid transformation sequence found." << endl;
    } else {
        cout << "Word Path: ";
        for (const string& word : wordPath) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
