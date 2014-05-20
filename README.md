OG Role Sync
===
This module will sync site roles with OG roles.

## Use cases

1. You have an OG called community.
2. Within community you have an admin role called *community admin*.
3. You have a site role called *group admin*.
4. You have given permissions (such as access to the admin menu, managing content) to *group admin* and you want all *community admin* to get this role.

### How can this module help?

By configuring the module to sync *group admin* role with *community admin* role:

1. When a user is granted the *community role* within a group, this module automatically assigns the user the *group admin* role.
2. When a user is revoked the *community role* within a group, this module will check if the user has *community role* across all community groups. If not, the *group admin* role is revoked.
