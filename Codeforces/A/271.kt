import java.util.*

fun main() {
    var y = readLine()!!.toInt() + 1
    while(true) {
        var bitset = BitSet(10)
        var tmp = y
        var beautiful = true
        for(d in 1..4) {
            if(!bitset.get(tmp % 10))
                bitset.set(tmp%10)
            else {
                beautiful = false
                break
            }
            tmp /= 10
        }
        if(beautiful) {
            println(y)
            break
        }
        y++;
    }
}