

bool isAnagram(char * s, char * t){
    int len1 = 0;
    int len2 = 0;
    int count1[26] = {0};
    int count2[26] = {0};
    int index;
    while(s[len1]){
        index = s[len1] - 'a';
        count1[index]++;
        len1++;
    }
    while(t[len2]){
        index = t[len2] - 'a';
        count2[index]++;
        len2++;
    }
    if(len1 != len2)
        return false;
    for(int i = 0; i < 26; i++){
        if(count1[i] != count2[i])
            return false;
    }
    return true;
}

