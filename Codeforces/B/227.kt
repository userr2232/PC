fun main() {
    var n = readLine()!!.toInt()
    var pos = IntArray(100000 + 1)
    readLine()!!.split(" ").map{ it.toInt() }.let {
        for((i, x) in it.withIndex()) {
            pos[x] = i
        }
    }
    readLine()
    var v = 0L
    var p = 0L
    readLine()!!.split(" ").map{ it.toInt() }.map {
        p += n - pos[it]
        v += pos[it] + 1
    }
    println("$v $p")
}