#include "Issue.hpp"
#include "CompositeIssue.hpp"


int main(void)
{
    CompositeIssue c = CompositeIssue("root");
    Issue folha1 = Issue("folha1", "aaaaaaaaaaa", "123/3/10");
    Issue folha2 = Issue("folha2", "bbbbbbbbbbb", "22/13/-1290");
    c.add(&folha1);
    c.add(&folha2);

    CompositeIssue pasta1 = CompositeIssue("pasta");
    Issue folha3 = Issue("la ele", "que esso", "data");
    pasta1.add(&folha3);
    c.add(&pasta1);

    c.get();

    return 0;
};