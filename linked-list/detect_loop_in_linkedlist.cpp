bool detectLoop(Node *head)
{
    // your code here

    Node *slowp = head, *fastp = head;

    while (slowp && fastp && fastp->next)
    {
        slowp = slowp->next;
        fastp = fastp->next->next;
        if (slowp == fastp)
        {
            return true;
        }
    }

    return false;
}