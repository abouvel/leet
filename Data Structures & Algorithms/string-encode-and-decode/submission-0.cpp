class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s;
        for (const string& w : strs) {
            s += static_cast<char>(w.size());  // <<< 1-byte length *for this string*
            s += w;                            //    the string itself
        }
        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(const string& s) {
        vector<string> v;
        size_t i = 0;
        while (i < s.size()) {
            int len = static_cast<unsigned char>(s[i]); // read 1-byte length
            v.push_back(s.substr(i + 1, len));          // grab that many chars
            i += 1 + len;                               // hop to next length byte
        }
        return v;
    }
};

