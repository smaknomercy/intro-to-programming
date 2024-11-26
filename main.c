bool isIsomorphic(char *s, char *t)
{
    int length1 = strlen(s);
    int length2 = strlen(t);
    if (length1 != length2)
    {
        return false;
    }

    int arr1[256] = {0};
    int arr2[256] = {0};

    for (int i = 0; i < length1; i++)
    {
        int charS = (int)s[i];
        int charT = (int)t[i];

        if (arr1[charS] == 0 && arr2[charT] == 0)
        {
            arr1[charS] = charT;
            arr2[charT] = charS;
        }
        else if (arr1[charS] != charT || arr2[charT] != charS)
        {
            return false;
        }
    }
    return true;
}