import kotlin.math.*

fun main() {
    val n = readLine()!!.toInt()
    for(i in 1..n) {
        var (a, b) = readLine()!!.split(" ").map{ it.toLong() }
        if(a < b) a = b.also { b = a }
        if(2 * b <= a) println(b)
        else {
            var q = 0L
            var x = a - b
            q += x
            a -= 2 *x
            b -= x
            if(a < b) a = b.also { b = a }
            q += 2 * b / 3
            if(b % 3L == 2L)
                q++
            println(q)
        }
    }
}