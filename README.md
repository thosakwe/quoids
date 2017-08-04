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

# Living Things
Living things have additional properties:
* Health - This is a scalar. As time progresses, this will always fall. Once it reaches 0, the thing dies. Different organisms have different ways of replenishing their health.

Living things can also reproduce with other living things, under criteria specific to a species. Organisms of any health can reproduce, so dying things can still send their "genes" on to the next generation. Different species reproduce in different ways. For example, plants simply spread a number of seeds in available spaces. Of course, this means that plants spawned against walls can potentially die out.

# Plants
In addition to producing seeds, plants can evolve *emissions* of arbitrary elements or compounds. These can potentially be poisonous to mammals.

# Mammals
There are a few kinds of mammals in Quoids (will be defined later!). Some eat plants, some eat only other mammals, and some can eat both. 

Mammals are capable of comprehending *relationships* with other things. Different species can understand certain kinds of relationships. For example, animals that are commonly prey for the most part only understand that they can eat plants, and that they should flee predators.

Mammals have *speed*, and *strength*. More strength means that the mammal can break things of greater hardness. When it comes to killing things within range (always 1 space for hand-to-hand/paw combat), strength can be inflicted as direct damage to another mammal's health, potentially killing it.

Mammals have *vision*, which determines the amount of spaces they can see relative to their own position at the start of any turn. The more vision, the more decisions an individual will make. Better vision can evolve within mammals.

Mammals can be poisoned by certain elements or compounds. If a poison hits, then it will subtract a significant amount of health from the mammal.

# Death
When a living thing dies, it becomes a *dead* version of whatever it was. The carcass's mass will deteriorate at a fixed rate, which is randomly determined at start-up. The nutritional value of the carcass depends on how much mass is left.

# Quoids
Think *caveman*. A Quoid is a type of mammal with an enhanced capacity for decision-making.

Quoids have enhanced social capabilities, somewhat like humans. They can comprehend levels of *trust* within relationships, which tend to increase the more turns another Quoid is seen within the range of vision.

Quoids also have *emotion*, a scalar which can affect their tendencies to carry out certain actions.

Quoids' decisions can be influenced by a variety of factors, which can potentially lead to societies forming. For example, a Quoid may choose to move closer to another Quoid, depending on the level of trust in their relationship, and effectively follow them around. I imagine that sizeable groups could form out of this. Quoids also consciously choose whether to reproduce with other Quoids, depending on the level of trust and emotion between them. This varies depending on the Quoid, and also genetically.
