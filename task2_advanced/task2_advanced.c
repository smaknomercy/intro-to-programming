char* longestCommonPrefix(char** strs, int strsSize) {
    int position = 0;
    while (1) {
        char symbol = strs[0][position];
        if (symbol == '\0')
            break;
        for (int i = 1; i < strsSize; i++) {
            if (strs[i][position] != symbol) {
                strs[0][position] = '\0';
                return strs[0];
            }
        }
        position++;
    }
    strs[0][position] = '\0';
    return strs[0];
}