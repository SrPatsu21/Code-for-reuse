yuml
{

//LivingEntity
[<<Abstract>>AbstractEntity]<-[<<Abstract>>AbstractLivingEntity]
[<<Abstract>>AbstractLivingEntity]<-[<<Abstract>>Mobs]
[<<Abstract>>AbstractLivingEntity]<-[<<Abstract>>AbstractCharacter]
[<<Abstract>>AbstractCharacter]<-[Hero]
[<<Abstract>>AbstractCharacter]<-[Princess]
[<<Abstract>>Mobs]<-[monster]

//itens
[<<Interface>>InterfaceCollectionable]<-[<<Abstract>>AbstractTakeOnceItem]
[<<Interface>>AbstractTakeOnceItem]<-[<<Abstract>>AbstractUsableItens]
[<<Abstract>>AbstractUsableItens]<-[sword]
[<<Abstract>>AbstractUsableItens]<-[hammer]

//attributs
[<<Interface>>InterfaceCollectionable||#setAsTaked();]
[<<Abstract>>AbstractTakeOnceItem|-taked: bool; -owner:AbstractLivingEntity*|+isTaked(); +setAsTaked(); +setAsUntaked(); +setOwner(); +removeOwner(); +getOwner()]
[<<Abstract>>AbstractUsableItens|-durability: int; -damage: int|+setDurability(); +reduceDurability(); +reduceDurability(); +getDurability(); +setDamage(); +getDamage(); +useItem()]
[hammer||+useItem()]
[sword||+useItem()]

[<<Abstract>>AbstractEntity|-bout: int|+getBout(); +passBout();]
[<<Abstract>>AbstractLivingEntity|-maxlife: int; -life: int; -damage: int; -level: int|+atackEnemy(); +receiveDamage(); +lifeRegen(); +levelUp(); +getLevel(); +getDamage(); +getLife(); +getMaxLife(); +passBout()]
[<<Abstract>>Mobs||+passBout()]
[<<Abstract>>AbstractCharacter| -item: AbstractUsableItens*| +atackEnemy(); +getItem(); +useItem(); +setItem(); +passBout();]

}
