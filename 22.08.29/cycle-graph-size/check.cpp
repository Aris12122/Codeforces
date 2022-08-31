#include "testlib.h"

int INF = 1e9;

int main(int argc, char * argv[]) {
    registerTestlibCmd(argc, argv);

    int oufq = ouf.readInt(0, INF, "participant_queries");
    int ansq = ans.readInt(0, INF, "jury_queries");

    if (ansq > 15)
        quitf(_fail, "Limit is %d, but main solution have made %d queries", 15, ansq);

    if (oufq > 15)
        quitf(_wa, "Limit is %d, but solution have made %d queries", 15, oufq);

    quitf(_ok, "Number is guessed successfully with %d queries", oufq);
}
