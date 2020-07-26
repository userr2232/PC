import kotlin.system.*

fun main() {
    var (k, r) = readLine()!!.split(" ").map{ it.toInt() }
    for(i in 1..9) {
        if((i * k) % 10 == r || (i * k) % 10 == 0) {
            println(i)
            break
        }
    }
    println()
}