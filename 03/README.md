# CPP Module 03

## Goals
- Inheritence

## Lecture
- [Microsoft Learn/Shows C++ 04](https://learn.microsoft.com/en-us/shows/cplusplus-language-library/04) 

## ex00: Aaaaand... OPEN!

## ex01: Serena, my love!

## ex02: 

## ex03: 

### class ClapTrap

```cpp
class ClapTrap {
public:
	// OCCF
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	const std::string get_name_for_display() const;
	// getter && setter
private:
	std::string name_;
	int hit_;
	int energy_;
	int attack_damage_;
};
```

### class ScavTrap

```cpp
class ScavTrap : virtual public ClapTrap {
public:
	// OCCF
	void attack(const std::string &target);
	void guardGate();
	void set_is_guard(bool is_guard);
	const bool &get_is_guard() const;
private
	bool is_guard;
};
```

### class FragTrap

```cpp
class FragTrap : virtual public ClapTrap {
public:
	// OCCF
	void highFiveGuys();
};
```

### class DiamondTrap

```cpp
class DiamondTrap : public ScavTrap, public FragTrap {
public:
	// OCCF
	void whoAmI();
	const std::string get_name_for_display() const;
	// getter && setter
private:
	std::string name_;
};
```
