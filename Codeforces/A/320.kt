import kotlin.system.*

fun main() {
    val digits = readLine()!!.map(Character::getNumericValue)
    var i = 0
    while(i < digits.size) {
        if(digits[i] == 1) {
            if(i + 2 < digits.size && digits[i + 1] == 4 && digits[i + 2] == 4) i += 3
            else if(i + 1 < digits.size && digits[i + 1] == 4) i+=2
            else i++
        }
        else {
            println("NO")
            exitProcess(0)
        }
    }
    println("YES")
}