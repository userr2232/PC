fun main() {
    val n = readLine()!!.toInt()
    var count = 0
    for(i in 1..n) {
        val (p, v, t) = readLine()!!.split(" ").map{ it.toInt() }
        if(p + v + t >= 2)
            count++;
    }
    println(count)
}