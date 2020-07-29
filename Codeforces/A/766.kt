import kotlin.math.*

fun main() {
    var a = readLine()!!
    var b = readLine()!!
    if(a != b)
        print(max(a.length, b.length))
    else
        print(-1)
}