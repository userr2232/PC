import kotlin.math.*

fun main() {
    var (n, _) = readLine()!!.split(" ").map{ it.toInt() }
    var time = 0L
    var current = 1
    readLine()!!.split(" ").map{ it.toInt() }.forEach{
        if(it != current) {
            if(it > current)
                time += it - current
            else
                time += n - current + it
            current = it
        }
    }
    println(time)
}