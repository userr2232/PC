import kotlin.math.*

fun main () {
    operator fun List<Double>.component6() = this[5]
    operator fun List<Double>.component7() = this[6]
    operator fun List<Double>.component8() = this[7]
    val (n,k,l,c,d,p,nl,np) = readLine()!!.split(" ").map{ it.toDouble() }
    println(min(min(k * l / n / nl, p / n / np), c * d / n).toInt())
}