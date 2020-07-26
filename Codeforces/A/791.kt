fun main() {
    var (a, b) = readLine()!!.split(" ").map{it.toInt()}
    var years = 0;
    while(a <= b) {
        years++
        a *= 3
        b *= 2
    }
    println(years)
}