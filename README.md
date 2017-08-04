# quoids
Artificial intelligence, simulating the beauty and randomness of evolution on Earth.

# About
This is probably the weirdest thing I will ever write in my entire life. The goal of this program is to host an *environment*. That is all. While somewhat Earth-like, the terrain is far simplified, in order to make it relatively simple to code.

Each time an instance of the program is started, a virtual environment of a fixed size is created, in two dimensions.
There will be a random probability of an *object* being placed on any individual tile. Objects can be:
* A *plant*. In Quoids, there is one species of plant, which grows fruit, every so often. It will be interesting if the amount of time taken to yield fruit can vary in a genetic fashion. Plants can die if they do not receive sufficient amounts of water.
* A *seed*. A *seed*, if it receives a sufficient amount of water, will survive, and can grow into a plant after a certain number of days. Plants can produce seeds randomly, if they are healthy enough. There is no concept of pollination.
* Any number of moles of an *element* or *compound*. Alone, these do not have much use. Thus, an environment's chemistry simulator makes it possible to combine certain elements/compounds via chemical reactions. These can occur naturally, or eventually, intelligent beings can evolve to figure out how to produce these???
* Bodies of water, of random size. These, of course, have a finite amount of water, but rain can replenish them. You can also fill these up with water you have stored, but natural (is it really natural here?) will probably kill off anything dumb enough to do that.
* Quoids. These are most akin to primitive humans.

# Things
All things, whether living or nonliving, have some common traits:
* Mass - A scalar
* Volume - A vector, existing in two dimensions
* Hardness - A scalar
* Roughness - A scalar

# Living Things
Living things have additional properties:
* Health - This is a scalar. As time progresses, this will always fall. Once it reaches 0, the thing dies and is removed from existence entirely. Different organisms have different ways of replenishing their health.

Living things can also reproduce with other living things, under criteria specific to a species. Organisms of any health can reproduce, so dying things can still send their "genes" on to the next generation. Different species reproduce in different ways. For example, plants simply spread a number of seeds in available spaces. Of course, this means that plants spawned against walls can potentially die.

# Quoids
Think *caveman*.
