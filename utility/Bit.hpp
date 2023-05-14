// Gosper's hack: Iterate all the m-bit state where there are k 1-bits.
int state = (1 << k) - 1;
while (state < (1 << m))
{
    doSomething(state);

    int c = state & - state;
    int r = state + c;
    state = (((r ^ state) >> 2) / c) | r;
}

// iterate all subset, exclude 0
for (int subset=state; subset>0; subset=(subset-1)&state)
{
   DoSomething(subset);
}
