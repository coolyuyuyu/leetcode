# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.
print("Hello world")
s1 = ["Allocator","allocate","allocate","allocate","free","allocate","allocate","allocate","free","allocate","free"]
s2 = [[10],[1,1],[1,2],[1,3],[2],[3,4],[1,1],[1,1],[1],[10,2],[7]]
for i in zip(s1, s2):
    print(f".{i[0]}(", end='')
    print(*i[1], sep=", ", end='')
    print(')')
    
print()


["Allocator","allocate","allocate","allocate","allocate","free","free","free","allocate","allocate","allocate","allocate","free","free","free","free","free","free","free","allocate","free","free","allocate","free","allocate","allocate","free","free","free","allocate","allocate","allocate","allocate","free","allocate","free","free","allocate","allocate","allocate","allocate","allocate","allocate","allocate","free","free","free","free"]
[[50],[12,6],[28,16],[17,23],[50,23],[6],[10],[10],[16,8],[17,41],[44,27],[12,45],[33],[8],[16],[23],[23],[23],[29],[38,32],[29],[6],[40,11],[16],[22,33],[27,5],[3],[10],[29],[16,14],[46,47],[48,9],[36,17],[33],[14,24],[16],[8],[2,50],[31,36],[17,45],[46,31],[2,6],[16,2],[39,30],[33],[45],[30],[27]]
