/*Intuition: We can choose or not choose an element to flip/rotate. And during each decision we can see if the array is correct or not.
Time Complexity: O(2^N) 

To Improve this we can act greedy and pick the element of max frequency. This max freq element will be present at all indexes of the array.
Time Complexity: O(N), N = lengths of tops and bottoms array
Space Complexity: O(1), for hashmap as the map will only have 6 elements


*/
///With hashmap
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int,int>map;
        int maxFreq = INT_MIN;
        int maxElement;
        for (int i = 0; i < tops.size(); i++){
            int top = tops[i];
            int bottom = bottoms[i];
            map[top] += 1;
            map[bottom] += 1;
        }
        for ( auto KV: map){
            
            if ( maxFreq < KV.second){
                maxFreq = KV.second;
                maxElement = KV.first;
            }    
        }
        
        
        int topRot = 0, bottomRot = 0;
        for ( int i = 0; i < tops.size(); i++){
            
            
            if ( tops[i] != maxElement and bottoms[i] != maxElement){
                return -1;
            }
            
            if ( tops[i] != maxElement ){
                topRot +=1;
            }
            else if (bottoms[i] != maxElement ){
                bottomRot+=1;
            }

        }
        return min(topRot, bottomRot);
        
    }
};


//Without map: We check if the first element of tops is prensent in both arrays.
//and then check if the first element of the bottoms arrary is present in both arrays.
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = check(tops, bottoms, tops[0]);
        if ( result != -1) return result;
        return check(tops, bottoms, bottoms[0]);
    }
    int check ( vector<int>& tops, vector<int>& bottoms, int target){
        int botRot = 0, topRot= 0;
        for ( int i = 0; i < tops.size(); i++){
            
            if ( tops[i] != target and bottoms[i] != target){
                return -1;
            }
            if (tops[i] != target ) topRot += 1;
            else if ( bottoms[i] != target) botRot +=1;

        }
        return min(botRot, topRot);
        
    }
};