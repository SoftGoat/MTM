#include <string>

class HealthPoints {
public:

    /*
     * Default Constructor:
     * Initializes the HealthPoints object with default health values.
     */
    HealthPoints();
    /*
     * Constructor:
     * Initializes the HealthPoints object with the given health value.
     *
     * @param health - Initial health points.
     */
    HealthPoints(int health);

    /*
     * Copy Assignment Operator:
     * Assigns the health value from another HealthPoints object.
     *
     * @param health - Another HealthPoints object to copy.
     * @return Reference to the modified HealthPoints object.
     */
    HealthPoints& operator=(const HealthPoints& health);

    /*
     * Destructor:
     * Destroys the HealthPoints object.
     */
    ~HealthPoints() = default;

    /*
     * Addition Operator (+):
     * Adds the given health points to the current health.
     *
     * @param health - Health points to add.
     * @return Reference to the modified HealthPoints object.
     */
    HealthPoints& operator+(int health);


    /*
     * Addition Operator (+):
     * Adds the given health points to the current health.
     *
     * @param health - Health points to add.
     * @return Reference to the modified HealthPoints object.
     */
    HealthPoints& operator+(const HealthPoints& health);

    /*
     * Compound Addition Assignment Operator (+=):
     * Adds the given health points to the current health.
     * @param health - Health points to add.
     * @return Reference to the modified HealthPoints object.
     */

    
    HealthPoints& operator+=(int health);

    /*
     * Compound Addition Assignment Operator (+=):
     * Adds the given health points to the current health.
     * @param health - Health points to add.
     * @return Reference to the modified HealthPoints object.
     */

    
    HealthPoints& operator+=(const HealthPoints& health);

    /*
     * Subtraction Operator (-):
     * Subtracts the given health points from the current health.
     *
     * @param health - Health points to subtract.
     * @return Reference to the modified HealthPoints object.
     */
    HealthPoints& operator-(int health);

     /*
     * Subtraction Operator (-):
     * Subtracts the given health points from the current health.
     * @param health - Health points to subtract.   
     * @return Reference to the modified HealthPoints object.
     */
    HealthPoints& operator-(const HealthPoints& health);


    /*
     * Compound Subtraction Assignment Operator (-=):
     * Subtracts the given health points from the current health.
     * @param health - Health points to subtract.
     * @return Reference to the modified HealthPoints object.
     */
    HealthPoints& operator-=(int health);

    /*
     * Compound Subtraction Assignment Operator (-=):
     * Subtracts the given health points from the current health.
        * @param health - Health points to subtract.
     * @return Reference to the modified HealthPoints object.
     */

    HealthPoints& operator-=(const HealthPoints& health);

    /*
     * Equality Operator (==):
     * Compares the health points with the given value for equality.
     *
     * @param health - Health points to compare.
     * @return Boolean indicating if health points are equal.
     */
    bool operator==(int health);

        /*
        * Equality Operator (==):
        * Compares the health points with the given value for equality.
        * @param HealthPoints - Health points to compare.
        * @return Boolean indicating if health points are equal.
        */
    bool operator==(const HealthPoints& health);

    /*
     * Inequality Operator (!=):
     * Compares the health points with the given value for inequality.
     *
     * @param health - Health points to compare.
     * @return Boolean indicating if health points are not equal.
     */
    bool operator!=(int health);

        /*
        * Inequality Operator (!=) :
        * Compares the health points with the given value for equality.
        * @param HealthPoints - Health points to compare.
        * @return Boolean indicating if health points are not equal.    
        */
    bool operator!=(const HealthPoints& health);

    /*
     * Less Than Operator (<):
     * Compares the health points with the given value for less than.
     * @param health - Health points to compare.
     * @return Boolean indicating if health points are less than.
     */
    bool operator<(int health);

        /*
        * Less Than Operator (<) :
        * Compares the health points with the given value for equality.
        * @param HealthPoints - Health points to compare.
        * @return Boolean indicating if health points are less than.
        */
    bool operator<(const HealthPoints& health);

    /*
     * Greater Than Operator (>):
     * Compares the health points with the given value for greater than.
     * @param health - Health points to compare.
     * @return Boolean indicating if health points are greater than.
     */
    bool operator>(int health);

        /*
        * Greater Than Operator (>) :
        * Compares the health points with the given value for equality.
        * @param HealthPoints - Health points to compare.
        * @return Boolean indicating if health points are greater than.
        */
    bool operator>(const HealthPoints& health);

    /*
     * Less Than or Equal To Operator (<=):
     * Compares the health points with the given value for less than or equal to.
     *
     * @param health - Health points to compare.
     * @return Boolean indicating if health points are less than or equal to.
     */
    bool operator<=(int health);

    /*
     * Greater Than or Equal To Operator (>=):
     * Compares the health points with the given value for greater than or equal to.
     * @param HealthPoints - Health points to compare.
     * @return Boolean indicating if health points are greater than or equal to.
     */

    bool operator<=(const HealthPoints& health);

    /*
     * Greater Than or Equal To Operator (>=):
     * Compares the health points with the given value for greater than or equal to.
     *
     * @param health - Health points to compare.
     * @return Boolean indicating if health points are greater than or equal to.
     */
    bool operator>=(int health);

    /*
     * Greater Than or Equal To Operator (>=):
     * Compares the health points with the given value for greater than or equal to.
     *
     * @param HealthPoints - Health points to compare.
     * @return Boolean indicating if health points are greater than or equal to.
     */

    bool operator>=(const HealthPoints& health);

    /*
     * Friend Function: Stream Insertion Operator (<<):
     * Outputs the health points to the given output stream.
     *
     * @param os - Output stream.
     * @param health - HealthPoints object to output.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& health);

    /*
     * Friend Function: Addition Operator (+):
     * Adds the given health points to the current health.
     *
     * @param health1 - Health points to add.
     * @param health2 - HealthPoints object to add.
     * @return New HealthPoints object with the added health points.
     */
    friend HealthPoints operator+(int health1, const HealthPoints& health2);

    /*
     * Friend Function: Addition Operator (+):
     * Adds the given health points to the current health.
     *
     * @param health1 - Health points to add.
     * @param health2 - HealthPoints object to add.
     * @return New HealthPoints object with the added health points.
     */

    friend HealthPoints operator-(int health1, const HealthPoints& health2);

    /*
     * Friend Function: Equality Operator (==):
        * Compares the health points with the given value for equality.
        * 
        * @param health1 - Health points to compare.
        * @param health2 - HealthPoints object to compare.
        * @return Boolean indicating if health points are equal.
     
     */

    friend bool operator==(int health1, const HealthPoints& health2);

    class InvalidArgument{};

private:


    int m_health; // Current health points
    int m_maxHealth; // Maximum health points
    const int MINIMUM_MAX_HEALTH = 1; // Minimum allowed value for maximum health
    const int DEFAULT_HEALTH = 100; // Default value for health points
};
