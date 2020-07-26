fun main() {
    var (n, k) = readLine()!!.split(" ").map{ it.toInt() }
    var tmpk = 0
    for(i in 0..n-1) {
        if(tmpk == k) tmpk = 0
        print('a' + tmpk++);
    }
}