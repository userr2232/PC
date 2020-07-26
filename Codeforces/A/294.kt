fun main() {
    var n = readLine()!!.toInt()
    var l = readLine()!!.split(" ").map{ it.toInt() }.toMutableList()
    var m = readLine()!!.toInt()
    for(i in 1..m) {
        var (a, b) = readLine()!!.split(" ").map{ it.toInt() }
        if(a - 2 >= 0)
            l[a-2] += b - 1
        if(a < n)
            l[a] += l[a - 1] - b
        l[a - 1] = 0
    }
    for(i in 0..n-1) {
        println(l[i])
    }
}