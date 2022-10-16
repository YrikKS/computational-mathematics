class Vector(sizeVector: Int, element: (Int) -> Double) {
    private val vector = DoubleArray(sizeVector)

    init {
        vector.forEachIndexed { index: Int, d: Double -> vector[index] = element(index) }
    }

    fun getElement(index: Int) = vector[index]

    fun setElement(index: Int, value: Double) {
        vector[index] = value
    }

    fun getSize() = vector.size

    fun printVector() {
        println(vector.contentToString())
    }
}