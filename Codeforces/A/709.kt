fun main() {
    var (n, b, d) = readLine()!!.split(" ").map{ it.toInt() }
    val l = readLine()!!.split(" ").map{ it.toInt() }
    var total = 0
    var count = 0
    for(i in l.indices) {
        if(l[i] > b) continue
        total += l[i]
        if(total > d) {
            count++
            total = 0
        }
    }
    println(count)
}