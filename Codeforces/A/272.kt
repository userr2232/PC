fun main() {
    var n = readLine()!!.toInt() + 1
    val total = readLine()!!.split(" ").map{ it.toInt() }.reduce{ sum, e -> sum + e }
    var count = 0
    for(i in 1..5) {
        if((i + total) % n != 1)
            count++
    }
    println(count)
}