fun main() {
    var (n, x) = readLine()!!.split(" ").map{ it.toLong() }
    var icecreamLeft = x
    var distressed = 0L
    for(i in 1..n) {
        var (sign, d_) = readLine()!!.split(" ")
        var d = d_.toLong()
        if(sign == "+")
            icecreamLeft += d
        else {
            if(icecreamLeft < d) {
                distressed++
            }
            else {
                icecreamLeft -= d
            }
        }
    }
    println("$icecreamLeft $distressed")
}