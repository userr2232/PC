fun main() {
    var s = readLine()!!
    val (upperCases, lowerCases) = s.toCharArray().partition { it.isUpperCase() }
    if(lowerCases.size >= upperCases.size)
        println(s.toLowerCase())
    else
        println(s.toUpperCase())
}