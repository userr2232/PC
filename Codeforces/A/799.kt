import kotlin.math.*

fun main() {
    var (n, t, k, d) = readLine()!!.split(" ").map{ it.toInt() }
    var time_A = ceil(n.toDouble() / k) * t
    var time_B = 0
    var oven1 = false
    var oven2 = false
    while(true) {
        if(time_B % t == 0){
            oven1 = false
            if(n > 0) {
                n -= k
                oven1 = true
            }
        }
        if(time_B >= d && (time_B - d) % t == 0) {
            oven2 = false
            if(n > 0) {
                n -= k
                oven2 = true
            }
        }
        if(!oven1 && !oven2) break
        time_B++
    }
    if(time_A <= time_B) println("NO")
    else println("YES")
}