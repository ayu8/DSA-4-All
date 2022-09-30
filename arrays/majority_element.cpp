int majorityElement(int a[], int size)
{

    int maj_index = 0, count = 1;

    for (int i = 1; i < size; i++)
    {
        if (a[maj_index] == a[i])
        {
            count++;
        }
        else
        {
            count--;
        }

        if (count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }

    count = 0;

    for (int i = 0; i < size; i++)
    {
        if (a[i] == a[maj_index])
        {
            count++;
        }
    }

    if (count > size / 2)
    {
        return a[maj_index];
    }
    return -1;
}