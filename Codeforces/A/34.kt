import kotlin.math.*

fun main() {
    readLine()
    readLine()!!.split(" ").map{ it.toInt() }.let {
        var last = 0
        var min = 0
        for((i, x) in it.withIndex()) {
            if(i == 0) {
                min = abs(x - it[it.size - 1])
                continue
            }
            var diff = abs(x - it[i - 1])
            if(diff < min) {
                last = i
                min = diff
            }
        }
        if(last > 0)
            println("${last + 1} $last")
        else
            println("1 ${it.size}")
    }
}