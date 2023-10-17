
//Your declarations and implementations would go here
class Vehicle
{
public:
    Vehicle(string name);
    virtual ~Vehicle();
    virtual string id() const;
    virtual string description() const = 0;
    virtual bool canHover() const;
private:
    string m_name;
};

class Drone : public Vehicle
{
public:
    Drone(string d_name);
    virtual ~Drone();
    virtual string description() const;

private:
};

class Balloon : public Vehicle
{
public:
    Balloon(string b_name, double dia);
    virtual ~Balloon();
    virtual string description() const;

private:
    double m_dia;
};

class Satellite : public Vehicle
{
public:
    Satellite(string s_name);
    virtual ~Satellite();
    virtual string description() const;
    virtual bool canHover() const;

private:
};

//VEHICLE IMPLEMENTATION

Vehicle::Vehicle(string name)
{
    m_name = name;
}

Vehicle::~Vehicle()
{

}

bool Vehicle::canHover() const
{
    return true;
}

string Vehicle::id() const
{
    return m_name;
}

//DRONE IMPLEMENTATION

Drone::Drone(string d_name)
    :Vehicle(d_name)
{

}

Drone:: ~Drone()
{
    cout << "Destroying " << id() << ", " << description() << endl;
}

string Drone::description() const
{
    return "a drone";
}

//BALLOON IMPLEMENTATION

Balloon::Balloon(string b_name, double dia)
    :Vehicle(b_name)
{
    m_dia = dia;
}

Balloon::~Balloon()
{
    cout << "Destroying the balloon " << id() << endl;
}

string Balloon::description() const
{
    if (m_dia >= 8) {
        return "a large balloon";
    }
    else {
        return "a small balloon";
    }
}

//SATELLITE IMPLEMENTATION

Satellite::Satellite(string s_name)
    :Vehicle(s_name)
{

}

Satellite::~Satellite()
{
    cout << "Destorying the satellite " << id() << endl;
}

string Satellite::description() const
{
    return "a satellite";
}

bool Satellite::canHover() const
{
    return false;
}