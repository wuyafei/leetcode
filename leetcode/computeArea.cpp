class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left=max(A,E);
        int right=min(C,G);
        int top=min(D,H);
        int bot=max(B,F);
        int area=(D-B)*(C-A)+(H-F)*(G-E);
        if(right>left && top>bot)
            return area-(right-left)*(top-bot);
        else
            return area;
    }
};