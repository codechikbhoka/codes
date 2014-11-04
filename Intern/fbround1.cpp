/*
OneEditApart("cat", "dog") = false
OneEditApart("cat", "cats") = true
OneEditApart("cat", "cut") = true
OneEditApart("cat", "cast") = true
OneEditApart("cat", "at") = true
OneEditApart("at", "cat") = true
OneEditApart("cat", "act") = false
OneEditApart("cat", "cat") = false

abcdefg
abcdxsfg

OneEditApart(s1,s2) == OneEditApart(s2,s1)

"table" "taxle" // LC-subseq = 2

*/

bool OneEditApart(string s1, string s2) {
    
    int m = s1.length();
    int n = s2.length();
    
    if(m-n > 1 || n-m > 1)
    {
        return false;
    }
    
    
    
    if(m==n)
    {
        int count = 0;
        for(int i = 0; i<m ;i++)
        {
            if(s1[i] != s2[i])
            {
                count++;    
            }
        }
        
        if (count > 1)
            return false;
    }
    
    if (m > n) { swap(s1,s2); swap(m,n); }
    assert(m < n);
    
    
    if(n-m = 1)
    {
        count = 0;
        for(int i = 0, j=0; i< m, j<n ;i++,j++)
        {
            if(s1[i] != s2[j])
            {
                count++;
                j++;
                if(s1[i] != s2[j])
                    count++ ;
            }
            if (count > 1)
                return false;
        }
    }
        
        
        
        
        
        
        
    }

}